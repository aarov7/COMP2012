import turtle
import random
turtle.speed(0)
turtle.hideturtle()
turtle.width(3)
a = 21
while a > 15:
    for b in range(20, 10, -10):
        c = 8
        while c <= 9:
            for d in range(3, 4):
                e = 2
                while e < 14:
                    x = random.randint(-300, 300)
                    y = random.randint(-300, 300)
                    turtle.up()
                    turtle.goto(x, y)
                    turtle.down()
                    for f in range(4):
                        turtle.forward(20)
                        turtle.left(90)
                    turtle.forward(20)
                    e = e + 1
            c = c + 1
    a = a - 1

turtle.done()
