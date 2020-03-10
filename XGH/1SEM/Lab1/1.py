try:
    x = 3
    item = x[0]
except TypeError:
    #this will print only on a TypeError exception 
    print ("x isn't a list!")
else:
    # executes if the code in the "try" does NOT 
    # raise an exception
    print ("You didn't raise an exception!")
finally:
     #this will always print
     print ("processing complete")


name = 'John'
print(f'Good morning, {name}. How are you today?')


def foo(a: int, b: str, c: "param", d: 42):
    print(a, b, c, d)
foo(1, "2", 4, 23)