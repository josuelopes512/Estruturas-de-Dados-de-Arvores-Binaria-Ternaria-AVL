var doSearch = function(array, targetValue) {
    var min = 0;
    var max = array.length - 1;
    var guess;
    console.log("Tamanho do Vetor = " + array.length);
    for (let count = 0; min <= max; count++) {
        //while(min <= max){
            guess = Math.floor((min+max)/2);
            console.log("contador" + count);
            console.log("esq = " + min);
            console.log("dir = " + max);
            console.log("media = " + guess);
            console.log("\n");
            //println(guess);
            //count++;
            if(array[guess] === targetValue){ 
                console.log("contador" + count);
                //println(count);
                return guess; 
            }
            else if(array[guess]<targetValue){
                min=guess+1;
            }
            else{ 
                max = guess-1;
            }
        //}
    }
    return -1;
};
var primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 
    107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 
    173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311];

var result = doSearch(primes, 52);
//println("Found prime at index " + result);
console.log("Found prime at index " + result);
//Program.assertEqual(doSearch(primes, 73), 20);
//Program.assertEqual(doSearch(primes, 2), 0);
//Program.assertEqal(doSearch(primes, 97), 24);