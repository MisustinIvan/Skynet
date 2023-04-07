from PIL import Image
import csv
import os

def convertFile(image: str):
    img = Image.open(f"./img/{image}")
    img = img.convert("L")
    img = img.resize((16,16))
    img_arr = [pixel for pixel in img.getdata()]
    return img_arr


def main():
    file_list = os.listdir("./img")
    for file in file_list:
        arr = convertFile(file)
        with open(f"./csv/{os.path.splitext(file)[0]}","w", newline="") as f:
            writer = csv.writer(f)
            writer.writerow(arr)


main()
