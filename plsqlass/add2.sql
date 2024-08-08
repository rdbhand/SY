delimiter //
create procedure add2(a int,b int)
begin
declare c int;
set c=a+b;
select concat("Addition ",c);
end
//