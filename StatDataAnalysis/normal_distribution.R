logLikelifood.normal <- function(x){
  return(-x**2/2)
}
sampling <- function(sample.length=1000, stepwidth=1, initial=0){
  samples <- vector("numeric", sample.length)
  last.sample <- initial
  samples[1] <-  last.sample
  last.ll <- logLikelifood.normal(last.sample)
  for(i in 2:sample.length){
    new.sample <- last.sample + runif(1, min=-stepwidth, max=stepwidth)
    new.ll <- logLikelifood.normal(new.sample)
    r <- runif(1, min=0, max=1)
    if((new.ll > last.ll) || (r < exp(new.ll - last.ll))){
      last.sample <- new.sample
      last.ll <- new.ll
    }
    samples[i] <- last.sample
  }
  return(samples)
}

x <- sampling(10**4)[seq(1, 10**4, by=10)]
y <- sampling(10**4)[seq(1, 10**4, by=10)]
z <- sampling(10**4)[seq(1, 10**4, by=10)]
rgl::plot3d(x, y, z)