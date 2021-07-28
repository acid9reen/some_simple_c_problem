import random
import string


def main():
    N = 10_000_000

    with open("str.txt", "w") as out:
        out.write(''.join(random.choice(string.ascii_letters) for _ in range(N)))


if __name__ == "__main__":
    main()
