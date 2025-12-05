import os
import subprocess

def user_interface():
    print("===== Data Converter =====")
    input_file = input("Enter path to input file: ")
    output_file = input("Enter path to output file: ")

    # بررسی موجود بودن فایل
    if not os.path.exists(input_file):
        print("Input file does not exist!")
        return

    # فراخوانی برنامه C برای پردازش داده
    c_program = "./converter"  # ویندوز: converter.exe
    subprocess.run([c_program, input_file, output_file])

    print(f"Processing done! Output saved to: {output_file}")

if __name__ == "__main__":
    user_interface()
