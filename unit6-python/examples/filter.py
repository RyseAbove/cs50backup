from PIL import Image, ImageFilter

before = Image.open("tower.bmp")

after = before.filter(ImageFilter.BLUR)
after.save("output.bmp")

after2 = before.filter(ImageFilter.SHARPEN)
after2.save("output2.bmp")

after3 = before.filter(ImageFilter.SMOOTH)
after3.save("output3.bmp")
