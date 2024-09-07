from PIL import Image
import re

# getting input message to encode
message = input().strip()
colors = [ord(letter) for letter in message.lower()]

# creating new jpg
dimension = 0
pixel_width_scalar = 10

while dimension**2 < (len(message) // 3 + 1):
    dimension += 1
dimension *= pixel_width_scalar
image = Image.new('RGB', (dimension, dimension))
        
# converting colors in range 0 - 255
colors = [color for color in colors]

# writing colors to image
p = 0
for i in range(0, dimension, pixel_width_scalar):
    for j in range(0, dimension, pixel_width_scalar):
        try:
            color_input = (colors[p], colors[p + 1], colors[p + 2])
        except:
            if p % 3 == 1:
                color_input = (colors[p], 0, 0)
            elif p % 3 == 2:
                color_input = (colors[p], colors[p + 1], 0)
        for a in range(pixel_width_scalar):
            for b in range(pixel_width_scalar):
                image.putpixel((i + a, j + b), color_input)
        p += 3
        if p >= len(colors):
            break
    if p >= len(colors):
        break

# saving image
image.save(r"D:\College Work\Computer Science\Programming\Random\message.png", "PNG")