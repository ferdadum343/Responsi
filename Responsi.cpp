#include <iostream>
#include <conio.h>
using namespace std;
uses crt;
type pointer1=^rec_antri;
		rec_antri=record
		no_antrian:byte;
		next1:pointer1;
		end;
type pointer2=^rec_tiket;
		rec_tiket=record
		no_antri:byte;teater1:string;j_tiket:byte;
		subtot:longint;
		next2:pointer2;
		end;
type rec_bioskop=record
		teater,judul:string;stok,terjual,sisa:byte;
		harga:longint;
		end;
		larik_bioskop=array[1..4] of rec_bioskop;
	var awal1,akhir1:pointer1;
		awal2,akhir2:pointer2;
		bioskop:larik_bioskop;
		n,i,pil:byte;
		
procedure isi_bioskop(var x:larik_bioskop);
begin
writeln('Mengisi bioskop ');
x[1].teater:='teater 1 ';x[1].judul:=' Star wars the last jedi ';
x[1].stok:=20;x[1].harga:=20000;x[1].terjual:=0;
x[1].sisa:=x[1].stok:=x[1].terjual;
x[2].teater:='teater 1 ';x[2].judul:=' Susah sinyal ';
x[2].stok:=20;x[2].harga:=30000;x[2].terjual:=0;
x[2].sisa:=x[2].stok:=x[2].terjual;
x[3].teater:='teater 1 ';x[3].judul:=' Ayat ayat cinta 2 ';
x[3].stok:=20;x[3].harga:=35000;x[3].terjual:=0;
x[3].sisa:=x[3].stok:=x[3].terjual;
x[4].teater:='teater 1 ';x[4].judul:=' Anak langit ';
x[4].stok:=20;x[4].harga:=25000;x[4].terjual:=0;
x[4].sisa:=x[4].stok:=x[4].terjual;

function habis(x:larik_bioskop):boolean;
begin
if (x[1].sisa=0 and (x[2].sisa=0) and (x[3].sisa=0) and (x[4].sisa=0) then
habis:=true else:=false;
end;

procedure masuk_antrian(var x,y:pointer1);
var baru:pointer1;
begin
new(baru);inc(n);baru^.no_antrian:=n;baru^.next1:=nil;
writeln(' Selamat datang di antrian bioskop XXX ');
writeln(' Anda mendpat nomor antrian ', n , ' mohon tunggu sebentar ');
if x:=nil then begin x:=baru;y:=baru;end
else begin y^.next1:=baru;y:=baru;end;
end;

procedure cetak_antrian(var x,y:pointer1);
var bantu:pointer1;
begin
writeln('Daftar antrian bioskop ');
writeln('-------------------------------');
writeln('Posisi no antrian ');
writeln('--------------------------------');
new(bantu);bantu:=x;1:=0;
while bantu<> nil do
begin
	inc(i); writeln(i:4,'     ',bantu^.no_antrian:4);
	bantu:=bantu^.next;
end;
writeln('-------------------------------');
writeln('Saat ini terdapat ', i , ' pengantre ');
writeln('----------------------------------');
end;

procedure cetak_bioskop(var x:larik_bioskop);
var tot:longint;
begin
tot:=0;
writeln('Rekap penjualan tiket ');
writeln('--------------------------------------------------------------------------');
writeln('Teater		Judul Film		Harga		Stok		Terjual		Sisa ');
writeln('---------------------------------------------------------------------------');
for i:=1 to 4 do
begin tot:=tot+(x[i].harga*x[i].terjual);
		writeln(x[i].teater:7,' ',x[i].judul:15,' ',x[i].harga:8,' ', 
		x[i].stok:3,' ',x[i].terjual:3,' ',x[i].siaa:3);
	end;
writeln('--------------------------------------------');
writeln('Total pendapatan hari ini Rp ,' tot:10 );
writeln('-----------------------------------------');
end;
procedure layanan(var x,y:pointer1;var x1,y1:pointer2;var z:larik_bioskop);
var pil1,j:byte;
var hapus:pointer1;
begin
writeln('layanan penjualan bioskop');
new(hapus);hapus:=x;
writeln

begin
isi_bioskop(bioskop);
new(awal1);new(akhir1);new(awal2);new(akhir2);
awal1:=nil;akhir1:=nil;awal2:=nil;akhir2:=nil;n:=100;
repeat
	clrscr;
	writeln('Pengelolaan tiket bioskop XXX' );
	writeln('1. Masuk antrian');
	writeln('2. Cetak antrian');
	writeln('3. Layanan pembelian tiket');
	writeln('4. Cetak rekap penjualan');
	writeln('5. Cetak detail transaksi');
	writeln('0. Selesai');
	write('Pilihan anda : ');readln(pil);
	case pil of
	1: if habis(bioskop) then writeln('maaf semua tiket habis ')
		else masuk_antrian(awal1,akhir1);
	2: if awal=nil then writeln('belum ada antrian tiket') else
		cetak_antrian(awal1,akhir1);
	4: cetak_bioskop(bioskop);
	0: writeln('terimakasih') else writeln('anda salah pilih menu');
	end;
	readln;
	until pil=0;
end.
