DATA TYPE

This programming language has the following data type:
- int
- bool
- float
- double
- string
- list
- ref

VARIABLE

To create variable following next construction:
Type namevariable 
int date

Also can use this construction (Type nameVariable) to chage data type variable. When the variable already exist in this namespace type of will be changed, 
otherwise variable will be created.

To create list variable use the following construction:
list variableName = {expression, expression, ...}

To create multidimensional list:
list variableName = 
{
{expression, expression, ...},
{expression, expression, ...},
...
}

To get element from list:
listVariable[expression]

To change value use: 
listVariable[expression] = expression

To create string variable:
string nameVariable = "Text"

To create variable with ref (reference) type, assign nameVariable to existing variable and then all actions will be reflected on connected variables:

ref refVariable = originalVariable

Arithmetic expressions with different variable type took type of the firs variable (if you take int + float you get a int variable type).

OPERATORS

The language has the follwoing arithmetic operators:
+ = plus,
- = minus,
* = multiplication,
/ = divide

The language has the follwoing boolean operators:
==,
!=,
<,
>,
<=,
>=

binary operators:
||,
&&,
!
true && true == true
true && false == false
true || false == true
false || true == true
true || true == true
!true = false
!false = true

CYCLES

The language has the following cycles:
while(expression)
{
body
}

for type valueName = expression; terms; iteration
{
body
}

do
{
  body
} while(expression)

Also you can use continue, break in seies. Example:
for int i =0; i< 10; i=i+1
{
  if (i == 3)
  {
      continue
  }
  doSomething
}

When continue do immediately new iteration and doSomething won't be done.
for int i =0; i< 10; i=i+1
{
  if (i == 3)
  {
      break
  }
  doSomething
}

When break do immediately cycle is broken.
If you want to create function you must use the following construction:
void nameFunction(arg....)
{
  body
}
All arguments which we pass in the function we pass only copy value.
If we wan`t to pass reference on variable. 
It's mean that all the manipulations that we will carry out on this value will be reflected on the original.
void nameFunction(&arg)
{
  body
}
if we want to return value we use statement return 
void nameFunction()
{
    return value
}

We can create your own type it make so
struct nameStruct
{
  int intVarialbe
  float floatVarialbe
}

if you want to create variable your type
TypeName nameValiable

if you want to get value from the variable you must use operator point nameStruct.intVarialbe

if you want to change value from the variable you must use operator point nad operator equal
nameStruct.intVarialbe = expression

if you want to display something use print, for example:
print expression

if you want input from a standard input device value to variable use input:
input nameVariable

If you want to get the symbol just pressed
getButton()

If you want to get size list you can use function len
list newList = {0, 1}
len(newList) - get 2





