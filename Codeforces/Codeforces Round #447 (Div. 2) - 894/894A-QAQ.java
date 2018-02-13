var str="";
str = readline();
 
var cnt = 0;
for(var i = 0;i<str.length;i++) {
 if(str[i]=='Q') {
  for(var j = i+1;j<str.length;j++) {
   if(str[j]=='A') {
    for(var k = j+1;k<str.length;k++) {
     if(str[k]=='Q')  cnt++;
    }
 
   }
  }
 } 
}
print (cnt);