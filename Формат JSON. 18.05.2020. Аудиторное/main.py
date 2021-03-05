import json
import random

mas = {}
logins = ("nik", "pic", "chick", "vova", "Killer228")

for i in range(0, 5):
  mas[str(logins[i])] = {"lastLoginTime": (str(random.randint(2000, 2020)) + "-" + str(random.randint(1, 12)) + "-" + str(random.randint(0, 28)) + "-" + str(random.randint(1, 24)) + "-" + str(random.randint(0, 60))), "time": random.randint(100, 10000)}

with open("json.json", "w", encoding = "utf-8") as output:
  json.dump(mas, output, ensure_ascii = False, indent = 2)