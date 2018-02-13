var str="";
var ar=[];
function go(l,r,x,c) {
 for(var i =l-1;i<r;i++) {
  if(ar[i]===x) ar[i] = c;
 }
}
var n = readline().split(' ');
str = readline();
ar= str.split("");
while(n[1]--) {
 var k = readline().split(' ');
 go(k[0],k[1],k[2],k[3]);
}
var ans ="";
for(var i = 0;i<ar.length;i++) ans +=ar[i];
print(ans);
 