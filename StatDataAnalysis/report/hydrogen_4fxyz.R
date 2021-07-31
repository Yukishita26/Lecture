logLikelifood.4fz <- function(rho, theta, phi){
  if(rho<0 || theta<0 || theta>pi || phi<0 || phi>2*pi){
    return(-10**9)
  }
  ll <- (6 + 2) * log(rho) - rho/2 + log(sin(theta) * (cos(theta)*sin(theta)**2*sin(phi*2))**2 + 1e-100)
  return(ll)
}
ortho2polar <- function(x, y, z){
  r <- sqrt(x**2 + y**2 + z**2)
  t <- acos(z/r)
  p <- sign(y) * acos(x / sqrt(x**2 + y**2))
  return(c(r, t, p))
}
polar2ortho <- function(rho, theta, phi){
  x <- rho * sin(theta) * cos(phi)
  y <- rho * sin(theta) * sin(phi)
  z <- rho * cos(theta)
  return(c(x, y, z))
}
sampling <- function(samples=1000,
                     stepwidth=c(1,1,1),
                     initial=c(1, pi/2, pi)){
  xyz.vec <- list(x=vector("numeric", samples),
                  y=vector("numeric", samples),
                  z=vector("numeric", samples))
  last.sample <- initial
  xyz <- polar2ortho(last.sample[1], last.sample[2], last.sample[3])
  xyz.vec$x[1] = xyz[1]
  xyz.vec$y[1] = xyz[2]
  xyz.vec$z[1] = xyz[3]
  last.ll <- logLikelifood.4fz(last.sample[1], last.sample[2], last.sample[3])
  for(i in 2:samples){
    new.sample <- last.sample + 
      c(runif(1, min=-stepwidth[1], max=stepwidth[1]),
        runif(1, min=-stepwidth[2], max=stepwidth[2]),
        runif(1, min=-stepwidth[3], max=stepwidth[3]))
    new.ll <- logLikelifood.4fz(new.sample[1], new.sample[2], new.sample[3])
    if((new.ll > last.ll) || (runif(1, min=0, max=1) < exp(new.ll - last.ll))){
      last.sample <- new.sample
      last.ll <- new.ll
    }
    xyz <- polar2ortho(last.sample[1], last.sample[2], last.sample[3])
    xyz.vec$x[i] = xyz[1]
    xyz.vec$y[i] = xyz[2]
    xyz.vec$z[i] = xyz[3]
  }
  return(xyz.vec)
}

sample.size <- 10**5 * 4
samples <- sampling(sample.size)
x <- samples$x[seq(1,sample.size,by=10)]
y <- samples$y[seq(1,sample.size,by=10)]
z <- samples$z[seq(1,sample.size,by=10)]
rgl::plot3d(x, y, z, size=1, xlim=c(-30,30), ylim=c(-30,30), zlim=c(-30,30))
