program sgu188;
var
len,n,t,i,j,k,s:longint;
v,l,ans:array[0..20]of longint;
begin
read(n,t);
for i:=1 to n do
    read(l[i]);
for i:=1 to n do
    read(v[i]);
for i:=1 to n do
    for j:=i+1 to n do
      if ord(v[i]>0)+ord(v[j]>0)=1
         then begin
           if v[i]>0
              then begin
                if l[i]<l[j] then len:=l[j]-l[i]
                         else len:=1000-l[i]+l[j];
              end
              else begin
                if l[j]<l[i] then len:=l[i]-l[j]
                         else len:=1000-l[j]+l[i];
              end;
           s:=t*(abs(v[i])+abs(v[j]));
           k:=s div 1000+ord(s mod 1000>=len);
           inc(ans[i],k); inc(ans[j],k);
         end;
for i:=1 to n-1 do
    write(ans[i],' ');
writeln(ans[n]);
end.
          
