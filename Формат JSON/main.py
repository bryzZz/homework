import requests, json

def getJSON():
  api_key = "dec6ed4d13f7837d344725eb1d08a3e5"
  base_url = "http://api.openweathermap.org/data/2.5/weather?"
  city_name = 'Irkutsk'#input("Enter city name : ")
  complete_url = base_url + "appid=" + api_key + "&q=" + city_name

  response = requests.get(complete_url)
  return response.json()

allInfo = getJSON()
# print(json.dumps(allInfo, indent = 2), end = "\n\n")

if allInfo["cod"] != "404":
  mainInfo = allInfo["main"]

  current_temperature = mainInfo["temp"]
  current_pressure = mainInfo["pressure"]
  current_humidiy = mainInfo["humidity"]

  weather_description = allInfo["weather"][0]["description"]
  print("Temperature = " + str(current_temperature - 273.15) + "°C")
  print("atmospheric pressure (in hPa unit) = " + str(current_pressure))
  print("humidity = " + str(current_humidiy) + "%")
  print("description: " + str(weather_description))
else:
  print(" City Not Found ")