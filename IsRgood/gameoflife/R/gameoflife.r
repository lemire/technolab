#!/usr/bin/env Rscript
args = commandArgs(trailingOnly=TRUE)
if (length(args)==0) {
  stop("At least one argument must be supplied (width).n", call.=FALSE)
}
width <- as.numeric(args[1])
sprintf("Using a %d x %d matrix", width, width)

x <- matrix(sample(0:1, width*width, replace= TRUE), ncol = width, nrow=width)
sprintf("Done with initialization... ")




gameoflife <- function(source) {
  target <- matrix(0,  ncol = width, nrow=width)
  for (i in (1:width)) {
    for (j in (1:width)) {
      currentvalue <- source[i,j]
      neighbors <- 0
      for (ineigh in (max(1,i-1) : min(width,i+1))) {
        for (jneigh in (max(1,j-1) : min(width,j+1))) {
          neighbors <- neighbors + source[ineigh,jneigh]
        }
      }
      if(currentvalue == 1) {
        if(neighbors < 2 || neighbors > 2) {
          target[i,j] <- 0
        } else {
          target[i,j] <- 1
        }
      } else {
        if(neighbors == 3) {
          target[i,j] <- 1
        } else {
          target[i,j] <- 0
        }
      }
    }
  }
  return (target)
}
for(i in (1:10)) {
  print(paste0("Iteration ", i))
  x  = gameoflife(x)
  image(x)
}
