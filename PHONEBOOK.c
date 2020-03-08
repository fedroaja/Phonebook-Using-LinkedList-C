
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define enter 13

typedef struct data{
    char nama[40];
    char telp[20];

    struct data *next,*prev;
}data;


int main(int argc, char const *argv[])
{
    data *head,*node,*tail,*curr,*temp,*temp2;
    int pilih,no,urutan,jml=0,counter,x;
    char temps[40];
    char input;
    char nama[40],nama2[40];
    char telp[20],telp2[20];
    head = NULL;
    FILE *fp =fopen("data.txt","r");
    while(!feof(fp))
    {
        node=(struct data*)malloc(sizeof (data));
        fscanf(fp,"%[^#]#%[^\n]\n",nama,telp);
        if(head==NULL)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->next=node->prev=NULL;

                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
            }
            else if(strcmp(nama,head->nama)==-1)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->next=node->prev=NULL;

                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
            }
            else if(strcmp(nama,tail->nama)==1)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->prev=node->next=NULL;
                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    node->prev=tail;
                    tail->next=node;
                    tail=node;
                }
            }
            else
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);

                node->next=node->prev=NULL;
                temp=head;
                while(temp!=NULL && strcmp(temp->nama,node->nama)==-1 || strcmp(temp->nama,node->nama)==0 )
                {
                    temp=temp->next;
                }
                node->prev=temp->prev;
                node->next=temp;

                temp->prev->next=node;
                temp->prev=node;
            }
            printf("%s",tail->nama);getch();
    }
    fclose(fp);
    while(1)
    {
        system("cls");
        no=01;
        jml=0;
        x=0;
        strcpy(nama,"\0");
        strcpy(telp,"\0");
        counter=1;
        printf("\n   MENU UTAMA\n");
        printf(" ------------------\n");
        printf(" 01. Tambah Data\n");
        printf(" 02. Pencarian Data\n");
        printf(" 03. Hapus Data\n");
        printf(" 04. Merubah Data\n");
        printf(" 05. Tampilkan Data\n");
        printf(" 06. Simpan Data\n");
        printf(" 10. Keluar\n");
        printf(" ------------------\n");
        printf(" Masukan Nomor Pilihan : ");
        scanf("%d",&pilih);fflush(stdin);
        node=(struct data*)malloc(sizeof (data));

        if(pilih == 1)
        {
            printf("\n");
            printf("Nama : ");scanf("%[^\n]",nama);fflush(stdin);
            printf("HP   : ");scanf("%[^\n]",telp);fflush(stdin);
            if(head==NULL)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->next=node->prev=NULL;

                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
            }
            else if(strcmp(nama,head->nama)==-1)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->next=node->prev=NULL;

                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
            }
            else if(strcmp(nama,tail->nama)==1)
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);
                node->prev=node->next=NULL;
                if(head==NULL)
                {
                    head=tail=node;
                }
                else{
                    node->prev=tail;
                    tail->next=node;
                    tail=node;
                }
            }
            else
            {
                strcpy(node->nama,nama);
                strcpy(node->telp,telp);

                node->next=node->prev=NULL;
                temp=head;
                while(temp!=NULL && strcmp(temp->nama,node->nama)==-1 || strcmp(temp->nama,node->nama)==0)
                {
                    temp=temp->next;
                }
                node->prev=temp->prev;
                node->next=temp;

                temp->prev->next=node;
                temp->prev=node;
            }


        }
        else if(pilih == 2)
        {
            curr=head;
            printf("\n");
            printf("Masukan nama yang di cari : ");scanf("%s",nama);
            while(1)
            {
                system("cls");
                printf("------------------------------------------\n");
                printf(" No. Nama                 No. Hp\n");
                printf("------------------------------------------\n");
                while(curr)
                {

                    if(strstr(curr->nama,nama)>0)
                    {
                        printf(" %02d. %-20s %-14s\n",no,curr->nama,curr->telp);
                        no++;
                    }
                    curr=curr->next;
                }
                printf("------------------------------------------\n");
                printf("Tekan Enter untuk proses selanjutnya...!");
                input=getch();
                if(input==enter)
                {
                    break;
                }
            }
        }
        else if(pilih == 3)
        {
            curr=head;
            while(curr)
            {
                jml++;
                curr=curr->next;
            }
            curr=head;
            printf(" Masukan Nomor Urut Data yang di hapus : ");scanf("%d",&urutan);
            if(urutan<=jml)
            {
                while(curr)
                {
                    if(counter==urutan)
                    {
                        if(head==NULL)
                        {
                            printf("Jumlah element dalam list = %d",jml);
                        }
                        else if(curr==head)
                        {
                            if(head==tail)
                            {
                                curr=head;
                                head=tail=NULL;
                                free(curr);
                            }else{
                                curr=head;
                                head=head->next;
                                head->prev=NULL;
                                free(curr);
                            }
                        }
                        else if(curr==tail)
                        {
                            if(head==tail)
                            {
                                curr=tail;
                                head=tail=NULL;
                                free(curr);
                            }else{
                                curr=tail;
                                tail=tail->prev;
                                tail->next=NULL;
                                free(curr);
                            }
                        }
                        else{
                            curr->prev->next=curr->next;
                            curr->next->prev=curr->prev;
                            free(curr);
                        }
                    }
                counter++;
                curr=curr->next;
                }
            }
            else{
                printf(" Jumlah elemen dalam list = %d",jml);
                getch();
            }

        }
        else if(pilih == 4)
        {
            curr=head;
            while(curr)
            {
                jml++;
                curr=curr->next;
            }
            curr=head;
            printf(" Masukan Nomor Urut Data yang akan diubah : ");scanf("%d",&urutan);fflush(stdin);
            strcpy(nama2,"\0");
            strcpy(telp2,"\0");
            if(urutan<=jml){
                printf(" Tekan Enter jika data tidak diubah...!\n");
            while(curr)
            {
                if(counter == urutan)
                {
                    printf(" Data : %s, dirubah menjadi : ",curr->nama);scanf("%[^\n]",nama2);fflush(stdin);
                    printf(" Data : %s, dirubah menjadi : ",curr->telp);scanf("%[^\n]",telp2);fflush(stdin);

                    if(strcmp(nama2,"\0")==0 && strcmp(telp2,"\0")==0)
                    {
                        strcpy(curr->nama,curr->nama);
                        strcpy(curr->telp,curr->telp);
                    }
                    else if(strcmp(nama2,"\0")==0)
                    {
                        strcpy(curr->nama,curr->nama);
                        strcpy(curr->telp,telp2);
                    }
                    else if(strcmp(telp2,"\0")==0)
                    {
                        strcpy(curr->nama,nama2);
                        strcpy(curr->telp,curr->telp);
                    }
                    else{
                        strcpy(curr->nama,nama2);
                        strcpy(curr->telp,telp2);
                    }
                }
                counter++;
                curr=curr->next;
            }
            curr=head;

            while(curr)
            {
                temp2=curr;
                while(temp2->next)
                {
                    if(strcmp(temp2->nama,temp2->next->nama)==1)
                    {
                        strcpy(temps,temp2->nama);

                        strcpy(temp2->nama,temp2->next->nama);
                        strcpy(temp2->next->nama,temps);
                    }
                    temp2=temp2->next;
                }
                printf(" %02d. %-20s %-14s\n",no,curr->nama,curr->telp);
                getch();
                curr=curr->next;
                }
            }
            else{
                printf(" Jumlah elemen dalam list = %d",jml);
                getch();
           }


        }
        else if(pilih == 5)
        {
            while(1)
            {
                system("cls");
                curr=head;
                printf("------------------------------------------\n");
                printf(" No. Nama                 No. Hp\n");
                printf("------------------------------------------\n");
                while(curr)
                {
                    printf(" %02d. %-20s %-14s\n",no,curr->nama,curr->telp);
                    no++;
                    curr=curr->next;
                }
                printf("------------------------------------------\n");
                printf("Tekan Enter untuk proses selanjutnya...!");
                input=getch();
                if(input==enter)
                {
                    break;
                }
            }
        }
        else if(pilih == 6)
        {
            curr=head;
            FILE *fr=fopen("data.txt","w");
            while(curr)
            {
                fprintf(fr,"%s#%s\n",curr->nama,curr->telp);
                curr=curr->next;
            }
            fclose(fr);

        }
        else if(pilih == 10)
        {
            break;
        }
        else
        {
            printf("Input yang dimasukan salah");
            getch();
        }
    }
    return 0;
}
