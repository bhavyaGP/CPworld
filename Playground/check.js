let createcounter=function(n){
    let cnt=n;
    return function(){
        cnt++;
        return cnt;
    }
}
let counter=createcounter(5);
console.log(counter());
console.log(counter());
console.log(counter());
