#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

struct Kuyruk {
    struct Dugum* bas;
    struct Dugum* son;
};

struct Kuyruk* kuyrukOlustur() {
    struct Kuyruk* yeniKuyruk = (struct Kuyruk*)malloc(sizeof(struct Kuyruk));
    yeniKuyruk->bas = NULL;
    yeniKuyruk->son = NULL;
    return yeniKuyruk;
}

int bosMu(struct Kuyruk* kuyruk) {
    return (kuyruk->bas == NULL);
}

void ekle(struct Kuyruk* kuyruk, int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    if (bosMu(kuyruk)) {
        kuyruk->bas = yeniDugum;
    }
    else {
        kuyruk->son->sonraki = yeniDugum;
    }
    kuyruk->son = yeniDugum;
}

void sil(struct Kuyruk* kuyruk) {
    if (bosMu(kuyruk)) {
        printf("Kuyruk bos!\n");
        return;
    }
    struct Dugum* silinecekDugum = kuyruk->bas;
    kuyruk->bas = kuyruk->bas->sonraki;
    free(silinecekDugum);
}

void goruntule(struct Kuyruk* kuyruk) {
    if (bosMu(kuyruk)) {
        printf("Kuyruk bos!\n");
        return;
    }
    struct Dugum* dugum = kuyruk->bas;
    printf("Kuyruk: ");
    while (dugum != NULL) {
        printf("%d ", dugum->veri);
        dugum = dugum->sonraki;
    }
    printf("\n");
}

int main() {
    struct Kuyruk* kuyruk = kuyrukOlustur();

    int secim, veri;

    do {
        printf("\n-----MENU-----\n");
        printf("1- Ekle\n");
        printf("2- Sil\n");
        printf("3- Goruntule\n");
        printf("4- Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            printf("Eklenecek veri: ");
            scanf("%d", &veri);
            ekle(kuyruk, veri);
            break;
        case 2:
            sil(kuyruk);
            break;
        case 3:
            goruntule(kuyruk);
            break;
        case 4:
            printf("Programdan cikiliyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 4);

    return 0;
}

