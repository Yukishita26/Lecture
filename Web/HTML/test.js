var r=0;
for(var i=1; i<=10; i++){
    r += i;
}
alert(r);
for(var i=0; i<100; i++){
    console.log(((i%3==0)? ((i%5==0)?"FizzBuzz":"Fizz") :((i%5==0)?"Buzz":i)));
}