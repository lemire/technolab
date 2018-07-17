print(0.4999999999999999 < 0.5)
print(1000.4999999999999999<1000.5)
x <- 4.0e7
print((8*x) * x + 1 * 1 + (-1) * (-1) + (2*x)*(-4*x))
printx <- function() {print(x)}

x <- 1
addonetox <- function() {
   x <- x + 1
}

x <- 0
printx()
g <- function() {
  x <- 1
  printx()
}
g()
