import matplotlib.pyplot as plt
import math
import time

def distance(lat1, lon1, lat2, lon2):
    r = 6371
    lat1 = math.radians(lat1)
    lat2 = math.radians(lat2)
    lon1 = math.radians(lon1)
    lon2 = math.radians(lon2)
    a = (math.sin((lat2 - lat1) / 2) ** 2 + math.cos(lat1) * math.cos(lat2) * math.sin((lon2 - lon1) / 2) ** 2)
    d = 2 * r * math.asin(a ** 0.5)
    return d

def get_roi(lats, lons, vals, roi):
    result = []
    for lat, lon, val in zip(lats, lons, vals):
        if roi[0] < lon < roi[1] and roi[2] < lat < roi[3]:
            result.append([lat, lon, val])
    return result

def thin_grid(points, min_distance = 1000):
        result = []
        p = points.pop()
        result.append(p)
        while points:
            p2 = points.pop()
            for p1 in result:
                if (distance(*p1[:2], *p2[:2]) < min_distance):
                    break
            else:
                result.append(p2)
        return result

def memoize(func):
    cache = dict()
    def wrapped(*args, **kwargs):
        print(f"Called at {time.time()}")
        param_hash = hash((args, tuple(kwargs.items())))
        if param_hash in cache:
            print("Get result from cache")
            print(f"hash == {param_hash}")
            return cache[param_hash]
        result = func(*args, **kwargs)
        cache[param_hash] = result
        return result
    return wrapped

@memoize  # Декоратор
def query(date: str, roi: tuple[float], min_distance: int=1000):
    with open(date, "r") as f:
        lats = []  # широта (latitude)
        lons = []  # долгота (longitude)
        vals = []  # Значение в этой точке координат
        for line in f.readlines()[1:]:  # Считываем все точки с файла
            lat, lon, val = list(map(float, line.split()))
            lats.append(lat)
            lons.append(lon)
            vals.append(val)
            
        #plt.scatter(lons, lats, vals)
        #plt.show() 

        result = get_roi(lats, lons, vals, roi)  # Ограничиваем область (убираем лишние точки)
        result = thin_grid(result, min_distance)  # Ограничиваем область (соблюдение минимальной дистанции между точками) (МЕДЛЕННЫЙ УЧАСТОК КОДА) aka строчка тяжёловес
    return result

  # ---------------- Проверка запроса ---------------------------

print("---------- Check work query -----------\n")

t = time.perf_counter()
result = query("2021-03-05.dat", (-125.0, -70.0, 28.0, 55.0), 200)
print(f"Elapsed {time.perf_counter() - t:.5f}")
print(f"Find points: {len(result)}")

lats = []
lons = []
vals = []
for lat, lon, val in result:
    lats.append(lat)
    lons.append(lon)
    vals.append(val)

plt.scatter(lons, lats, vals)
plt.show()

  # ----------------- Проверка кеша --------------------------

print("\n\n---------- Check work cache -----------\n\n")

t = time.perf_counter()
result = query("2020-01-01.dat", (-100.0, -80.0, 28.0, 45.0))
print(f"Elapsed {time.perf_counter() - t:.5f}\n")

t = time.perf_counter()
result = query("2020-01-01.dat", (-100.0, -80.0, 28.0, 45.0))
print(f"Elapsed {time.perf_counter() - t:.5f}")

print(distance(0, 0, 0, 180))