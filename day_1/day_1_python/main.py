
count = 0
with open('../input.txt') as file:
    lines= file.readlines()
    readings = []
    for line in lines:
        readings.append(int(line))
    previous = None
    for reading in readings:
        if previous and reading > previous:
            count += 1
            previous = reading
        else:
            previous = reading
    print(count)