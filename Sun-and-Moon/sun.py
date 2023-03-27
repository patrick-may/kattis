sunago, sun_p = map(int, input().split())
moonago, moon_p = map(int, input().split())

sunago = -1*sunago
moonago = -1*moonago

while sunago != moonago:
    while sunago < moonago:
        sunago += sun_p
    while moonago < sunago:
        moonago += moon_p

print(moonago)