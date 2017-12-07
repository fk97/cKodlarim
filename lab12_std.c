#include <stdio.h>
//Kullanıcıdan ürün kodunu, miktarını, birim fiyatını ve hangi ayda alım yağıldığını alarak
//gerekli güncellemeleri yapar, yeni alim sayısını (alimSayi) döndürür
int alinanUrunEkle(int alimUrunKod[], int alimUrunMiktar[],
				int alimUrunFiyat[], int alimAy[], int alimSayi)
{

	printf("Ürün kodunu giriniz:");
	scanf("%d", &alimUrunKod[alimSayi]);
	printf("Alım miktarını giriniz:");
	scanf("%d", &alimUrunMiktar[alimSayi]);
	printf("Birim fiyatı giriniz:");
	scanf("%d", &alimUrunFiyat[alimSayi]);
	printf("Ürün alımının yapıldığı ayı giriniz:");
	scanf("%d", &alimAy[alimSayi]);

	return alimSayi+1;

}

//ürün kodu verilen bir ürünün toplam satış miktarını döndürür
int urunSatisBul(int urunKod, int satimUrunKod[], int satimUrunMiktar[],
								int satimSayi)
{
	int toplamSatis = 0;
	for(int i=0; i<satimSayi; i++)
	{
		if(satimUrunKod[i] == urunKod)
		{
				toplamSatis +=  satimUrunMiktar[i];
		}
	}
	return toplamSatis;
}

//Kullanıcıdan ürün kodunu, miktarını, birim fiyatını ve hangi ayda satış yağıldığını alarak
//gerekli güncellemeleri yapar, yeni satım sayısını (alimSayi) döndürür
int satilanUrunEkle(int satimUrunKod[], int satimUrunMiktar[],
				int satimUrunFiyat[], int satimAy[], int satimSayi)
{	
    printf("Ürün kodunu giriniz:");
    scanf("%d", &satimUrunKod[satimSayi]);
    printf("Alım miktarını giriniz:");
    scanf("%d", &satimUrunMiktar[satimSayi]);
    printf("Birim fiyatı giriniz:");
    scanf("%d", &satimUrunFiyat[satimSayi]);
    printf("Ürün alımının yapıldığı ayı giriniz:");
    scanf("%d", &satimAy[satimSayi]);
    return satimSayi+1;

}


//Yapılan tüm satışların bütün bilgilerini ekrana yazdırır
void tumSatisListele(int satimUrunKod[], int satimUrunMiktar[],
				int satimUrunFiyat[], int satimAy[], int satimSayi)
{
    int i;
    for(i = 0; i < satimSayi; i++){
        printf("%d, %d, %d, %d\n", satimUrunKod[i], satimUrunMiktar[i], satimUrunFiyat[i], satimAy[i]);
    }

}

int aylikGiderBul(int ay, int alimUrunMiktar[], int alimUrunFiyat[], int alimAy[], int alimSayi){
    int i, toplamGider = 0;
    for(i = 0;i < alimSayi; i++){
        if(ay == alimAy[i]){
            toplamGider = (alimUrunFiyat[i]*alimUrunMiktar[i]) + toplamGider;
        }
    }
    return toplamGider;
}

int urunKarBul(int urunKod, int alimUrunKod[], int alimUrunFiyat[], int alimUrunMiktar[], int alimSayi, int satimUrunKod[], int satimUrunFiyat[], int satimUrunMiktar[], int satimSayi){
    int alim = 0, satim = 0, i, k, kar;
    for(i = 0; i < alimSayi; i++){
        if(urunKod == alimUrunKod[i]){
            alim = (alimUrunMiktar[i] * alimUrunFiyat[i]) + alim;
        }
    }
    for(k = 0; k < satimSayi; k++){
        if(urunKod == satimUrunKod[k]){
            satim = (satimUrunMiktar[k] * satimUrunFiyat[k]) + satim;
        }
    }
    kar = satim - alim;
    return kar;
}



/*
Ekrana yukarıdaki 6 işlemi yazdırıp kullanıcıdan bir seçim yapmasını ister
ve seçimi döndürür
*********************************************
***            NE YAPMAK İSTERSİNİZ?	  ***
1. Ürün alım eklemek
2. Ürün satım eklemek
3. Tüm satışları listelemek
4. Bir ürünün satış miktarını bulmak
5. Bir ayın toplam giderini bulmak
6. Bir ürünün toplam karını bulmak
7. Bir ürünün stok miktarı bulmak
*********************************************
*/
int menu(){
    int secim;
    printf("*********************************************\n***            NE YAPMAK İSTERSİNİZ?	  ***\n1. Ürün alım eklemek\n2. Ürün satım eklemek\n3. Tüm satışları listelemek\n4. Bir ürünün satış miktarını bulmak\n5. Bir ayın toplam giderini bulmak\n6. Bir ürünün toplam karını bulmak\n7. Bir ürünün stok miktarı bulmak\n*********************************************");
    scanf("%d", &secim);
    return secim;
}

int main()
{
	int alimSayi = 5;   //toplam alım sayısını gösterir. Alımla ilgili dizilerin uzunluğunu tutmak için
	int alimUrunKod[100] = {1,2,1,1,3};   //alınan ürünlerin kodunu tutar
	int alimUrunMiktar[100] = {20,50,30,20,40};  //alınan ürünlerin miktarını tutar
	int alimUrunFiyat[100] = {75,30,60,150,100};   //alınan ürünlerin fiyatını tutar
	int alimAy[100] = {1,1,2,2,3};		//alınan ürünün hangi ayda alındığını tutar

	int satimSayi = 4;   //toplam satım sayısını gösterir. Satımla ilgili dizilerin uzunluğunu tutmak için
	int satimUrunKod[100] = {1,2,1,2};   //satılan ürünlerin kodunu tutar
	int satimUrunMiktar[100]  = {8,15,5,35};  // satılan ürünlerin miktarını tutar
	int satimUrunFiyat[100] = {90,60,200,60};   // satılan ürünlerin fiyatını tutar
	int satimAy[100] = {2,2,2,3};		// satılan ürünün hangi ayda satıldığını tutar
    
    int exit = 0, secenek, urunKod, satimMiktar, giderAy, aylikGider, karMiktar;
    
    while(exit == 0){
        secenek = menu();
        if(secenek == 1){
            alimSayi = alinanUrunEkle(alimUrunKod, alimUrunMiktar, alimUrunFiyat, alimAy, alimSayi);
        }
        if(secenek == 2){
            satimSayi = satilanUrunEkle(satimUrunKod, satimUrunMiktar, satimUrunFiyat, satimAy, satimSayi);
        }
        if(secenek == 3){
            tumSatisListele(satimUrunKod, satimUrunMiktar, satimUrunFiyat, satimAy, satimSayi);
        }
        if(secenek == 4){
            printf("Hangi ürünün satışını bulmak istersiniz:\n");
            scanf("%d", &urunKod);
            satimMiktar = urunSatisBul(urunKod, satimUrunKod, satimUrunMiktar, satimSayi);
            printf("%d urunun satis miktarı %d\n", urunKod, satimMiktar);
        }
        if(secenek == 5){
            printf("Hangi ayın giderini bulmak istiyorsunuz:\n");
            scanf("%d", &giderAy);
            aylikGider = aylikGiderBul(giderAy, alimUrunMiktar, alimUrunFiyat, alimAy, alimSayi);
            printf("%d ayının gideri %d dir\n", giderAy, aylikGider);
        }
        if(secenek == 6){
            printf("Hangi ürünün karını bulmak istersiniz:\n");
            scanf("%d", &urunKod);
            karMiktar = urunKarBul(urunKod, alimUrunKod, alimUrunFiyat, alimUrunMiktar, alimSayi, satimUrunKod, satimUrunFiyat, satimUrunMiktar, satimSayi);
            printf("%d urunun kar miktarı %d\n", urunKod, karMiktar);
        }
        if(secenek == -1){
            exit++;
        }
    }
	/*
	Tanımladığınız dizileri ilgili aşağıdaki bilgilerle doldurduk.
	Alım
	Ürünkod				miktar			fiyat 		ay
	1					20				75			1
	2					50				30			1
	1					30				60			2
	1					20				150			2
	3					40				100			3
	Satım
	Ürünkod				miktar			fiyat 	    ay
	1 					90				2
	2					15				60			2
	1					5				200			2
	2					35				60			3

	*/
    

 	return 0;

}
