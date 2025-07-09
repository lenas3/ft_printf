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
