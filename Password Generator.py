import secrets
"""I have used secrets instead of random because it gives truely
unpredictable results than random. """

def password_generator():
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"

    length = int(input("Enter your desired password length: "))
    count = int(input("How many passwords do you want to generate: "))
    for i in range(count):
        password = ""
        for j in range(length):
            password += secrets.choice(characters)
        print(f"password  {i+1}: {password}.")
   
password_generator()