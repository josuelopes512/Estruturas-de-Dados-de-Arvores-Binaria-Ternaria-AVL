var isEven = function(n) {
    return n % 2 === 0;
};

var isOdd = function(n) {
    return !isEven(n);
};

var power = function(x, n) {
    println("Computing " + x + " raised to power " + n + ".");
    // base case
    if(n === 0){
        return 1;
    }
    if(n < 0){
        return 1/power(x, -n);
    }

    
    if (n >= 1 ) {
        if(isEven(n)){
            var y = power(x, n/2);
            if (isEven(n)) {
                return y * y;
            }
        }
        if (isOdd(n)) {
            y = power(x, n-1);
            return x * y;
        }
    }
    // recursive case: n is negative 
    // recursive case: n is odd
    // recursive case: n is even
};

var displayPower = function(x, n) {
    println(x + " to the " + n + " is " + power(x, n));
};

var result = isEven(primes, 52);
//println("Found prime at index " + result);
console.log("Found prime at index " + result);