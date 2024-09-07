from PIL import Image

# reading message from image
image = Image.open(r"D:\College Work\Year 1 Semester 1 (Sem 1)\Computer Lab\Programming\Random\message.png")
pixels = image.load()
dimension = image.size[0]
pixel_width_scalar = 10

# building sentence
numbers = [chr(k) for i in range(0, dimension, pixel_width_scalar) for j in range(0, dimension, pixel_width_scalar) for k in pixels[i, j]]
numbers = [element for element in numbers if element != '\x00']
sentence = ''.join(numbers)

print(sentence)