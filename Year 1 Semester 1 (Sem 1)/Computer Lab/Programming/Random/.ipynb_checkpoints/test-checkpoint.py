
# Importing Image from PIL package
from PIL import Image
 
# creating a image object
im = Image.open(r"D:\College Work\Computer Science\Programming\Random\message.png")
px = im.load()
print(type(px[4, 4]))
px[4, 4] = (0, 0, 0)
print (px[4, 4])
coordinate = x, y = 180, 79
 
# using getpixel method
print (im.getpixel(coordinate));