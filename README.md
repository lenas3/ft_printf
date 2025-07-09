*BUFFER MANAGEMENT*
ft_printf projesi için yayınlanmış subject dosyası, orijinal printf gibi buffer management yapmamamızı söylüyor.

C Dilinde Buffer Management Ne Demek? Buffer mangaemnet, bellek üzerinde geçici veri depolama alanları olan tamponların (yani bufferlar) 
nasıl oluşturulduğunu, kullanıldığını ve yönetildiğini ifade eder.

Standart C kütüphanseinde 3 tür bufferlama olabilir:

  1. unbuffered (tamponsuz): her karakter anında gönderilir.
  2. Line Buffered (Satır Tamponlu): Satır sonuna (\n) kadar biriktirilip sonra ekrana gönderilir.
  3. Fully Buffered (Tam Tampona Alnımış): Buffer tamamen dolana kadar biriktirilip sonra gönderilir. Terminal çıktıları genellikle 'linebuffered' olurken, dosya çıktıları genellkile 'fully buffered' olur.

Aşağıdaki çıktıyı örnek alalım:

    #include <stdio.h>
    
    int main() {
        printf("Merhaba ");
        printf("Dünya");
    
        printf("\n");
        return 0;
    }

_Burada 1. ve 2. printf ile birlikte Hello World çıktısı bekleriz, ancak neew line ekleyen printf olmasa da çıktı alabilir miyiz?_
Eğer new line gelen kadar Merhaba ve Dünya çıktılarıyla buffer dolmadıysa Fully Buffered durumu olamaz, eğer new line da yoksa ve buffer tam dolmamışsa terminale 
bir şey gönderilmeyebilir. Eğer new line olmasa da "Hello World" çıktısı alıyorsam, Hello ve World çıktıları buffer'ı doldurmuş ve Fully Buffered olarak terminale gönderilmiş demektir.

Biz kendi printf fonksiyonumuzda buffer managemnet yapmamamız 'unbuffered' çalışıyoruz anlamına gelir.


*VARIADIC FUNCTIONS*
variadic fonksyionlar , belirsiz sayıda argüman alan fonksiyonlardır. variadic fonksiyonları yazmak için *va_list, va_start, va_arg, va_end* gibi makrolar kullanılır.
  - va_list: sayısı belli olmayan argümanlar listesine erişimi sağlamak için kullanılır. içinde argümanların tutulduğu bir yapı diyebiliriz.
  - va_start: va_list'in başlangıç noktasını ayarlar. Yani sayısı bilinmeyen değişkenlere erişmeyeburadan başlanır.

        va_start(args, str);
yukarıdaki kod satırında, str sabitolarak verilmiş son parametredir. 
_int	ft_printf(const char *str, ...)_ tarzı bir fonksiyon tanımında ...'tan önceki son parametre olmak zorundadır.
  - va_arg(va_list arg, type): sıradaki argümanı 'type' olarak girilen türde döner. Her çağrıldığında bir sonraki argümana geçer. Burada type yazılırken en düşük tip olarak int girilebilir. Diğer türler için _'Default Argument Promotion**'_ gerçekleşir.
  - va_end(va_list args): kullanım sonunda çağrılmalıdır. "Artık değişken argümanlarla işim bitti, ca_list'İ kapatabilirim" demektir. va_start ve va_arg kullanıldıysa mutlaka sonunda va_end çağrılmalıdır. C99 standardı der ki: "Every *va_start* should be matched with a *va_end.*"
    
     _-> **Default Argument Promotion:_ va_arg'ın çekeceği veri tipi derleyici tarafından tutulmaz, biz belirleriz. Güvenli argüman çekimini sağlamak için düşük veri tipleri daha büyük veri tiplerine 'promote' edilir. Örneğin float, double'a; char veya unsigned char,  
    Çünkü zaten bu küçük veri tipleri stack'te int kadar yer kaplar. Derleyivi bu yüzden küçük türleri zaten int'miş gibi alır. Yani örneğin char türünde bir argüman çekmek istersem önce int olarak çekip type casting ile char'a cast'lemeliyim.
    




























