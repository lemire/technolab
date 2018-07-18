#!/usr/bin/env Rscript
args = commandArgs(trailingOnly=TRUE)
if (length(args)==0) {
  stop("At least one argument must be supplied (width).n", call.=FALSE)
}
width <- as.numeric(args[1])
sprintf("Using a %d x %d matrix", width, width)

x <- matrix(sample(0:1, width*width, replace= TRUE), ncol = width, nrow=width)
sprintf("Done with initialization... ")
counts <- matrix(0,  ncol = width, nrow=width)


sumcounts <- function(counts) {
  counts[] <- 0
  for (i in (1:width)) {
    for (j in (1:width)) {
      currentvalue <- x[i,j]
      if(currentvalue == 1) {
        if(i>1) {
          counts[i-1,j] <- counts[i-1,j] + 1
        }
        if(i>1 && j>1) {
          counts[i-1,j-1] <- counts[i-1,j-1] + 1
        }
        if(i>1 && j<width) {
          counts[i-1,j+1] <- counts[i-1,j+1] + 1
        }
        if(i<width && j>1) {
          counts[i+1,j-1] <- counts[i+1,j-1] + 1
        }
        if(i<width && j<width) {
          counts[i+1,j+1] <- counts[i+1,j+1] + 1
        }
        if(i<width) {
          counts[i+1,j] <-  counts[i+1,j] + 1
        }
        if(j>1) {
          counts[i,j-1] <- counts[i,j-1] + 1
        }
        if(j<width) {
          counts[i,j+1] <- counts[i,j+1] + 1
        }
      }
    }
  }
  return (counts)
}

gameoflife <- function(source) {
  for (i in (1:width)) {
    for (j in (1:width)) {
      currentvalue <- source[i,j]
      neighbors <- counts[i,j]
      if(currentvalue == 1) {
        if(neighbors < 2 || neighbors > 3) {
          source[i,j] <- 0
        } else {
          source[i,j] <- 1
        }
      } else {
        if(neighbors == 3) {
          source[i,j] <- 1
        } else {
          source[i,j] <- 0
        }
      }
    }
  }
  return (source)
}

for(i in (1:98)) {
  print(paste0("Iteration ", i))
  counts = sumcounts(counts)
  x = gameoflife(x)
}
for(i in (99:100)) {
  print(paste0("Iteration ", i))
  counts = sumcounts(counts)
  x = gameoflife(x)
  image(x)
}
