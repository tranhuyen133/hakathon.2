#include<stdio.h>
#include<string.h>

struct Student
{
	int id;
	char name [50];
	char birthday [50];
	char address [50];
	int status;
};
void displayStudent(struct Student arr[] , int size)
{
	for (int i = 0 ; i < size ; i++)
	{
		printf("id:%d\n",arr[i].id);
		printf("ten:%s\n",arr[i].name);
		printf("ngay sinh:%s\n",arr[i].birthday);
		printf ("dia chi :%s\n",arr[i].address);
		printf("trang thai : %d\n",arr[i].status);
		printf("------------------\n");
    }
}

int searchStudent(struct Student arr[], int size, char answer[50])
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, answer) == 0)
        {
            index = i;
        }
    }
    return index;
}
int searchStudentByName(struct Student arr[], int size, char answer[50]);

int main ()
{
	struct Student student1 = {1, "Nguyen Van A", "1/1/2004", "Ha Noi",0};
    struct Student student2 = {2, "Tran Van B", "2/2/2003", "Da Nang",1};
	
    struct Student studentList[100] = {student1, student2};
    int currentSize = 2;

	int choice;
	 while (choice != 7)
    {
        printf("************* MENU *************\n");
        printf("1. In toan bo danh sach sinh vien cung mot mang\n");
        printf("2. Them moi sinh vien vao vi tri cuoi cung\n");
        printf("3. Cap nhap thong tin cua sinh vien\n");
        printf("4. Xoa mot sinh vien \n");
        printf("5. Sap xep va in ra danh sach da duoc sap xep\n");
        printf("6. Tim kiem va in thong tin cua sinh vien \n");
        printf("7. Tim kiem va in ra toan bo thong tin cua sinh vien theo trang thai \n");
        
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            /* In ra toan bo danh sach sinh vien co trong Studenlist*/
            displayStudent (studentList, currentSize);
            break;
        case 2: 
            printf("2.1.Them moi sinh vien \n");
            float subChoice;
            scanf("%f", &subChoice);
            fflush(stdin);

            if (subChoice == 2.1f)
            {
                // Thêm sinh vien
                struct Student newStudent;

                printf("Nhap vào id cua sinh vien\n");
                scanf("%d", &newStudent.id);
                fflush(stdin);

                printf("Nhap vào ten cua sinh vien\n");
                gets(newStudent.name);

                printf("Nhap vào ngay sinh cua sinh vien\n");
                scanf("%s", newStudent.birthday);
                fflush(stdin);

                printf("Nhap vao dia chi cua sinh vien\n");
                gets(newStudent.address);

                printf("Nhap vao trang thai cua sinh vien\n");
                scanf("%d", &newStudent.status);
                fflush(stdin);

                studentList[currentSize] = newStudent;
                currentSize++;

                displayStudent(studentList, currentSize);
       		} else (subChoice == 2.2f);
			break;
			case 3 :
            {
			char answer[50];
            printf("Nhap vao thong tin sinh vien: \n");
            gets(answer);
            int searchIndex = searchStudent(studentList, currentSize, answer); // -1 || index
            if (searchIndex == -1)
            {
                printf("Khong tim thay du kieu vua nhap vao \n");
            }
            else
            {
                struct Student findStudent = studentList[searchIndex];
                printf("id: %d\n", findStudent.id);
                printf("Ten sinh vien: %s\n", findStudent.name);
                printf("ngay sinh: %s\n", findStudent.birthday);
                printf("dia chi: %s\n", findStudent.address);
                printf("trang thai: %d\n", findStudent.status);
                printf("------------------\n");
            }
            break;
        }
            case 4 :
            	// Xoa sinh vien
                {
				char answer[100];
                printf("Nhap vao sinh vien muon xoa: \n");
                gets(answer);

                int deleteIndex = searchStudent(studentList, currentSize, answer); // -1, index

                if (deleteIndex != -1)
                {
                    // { student1, student2, student3, student4} ... }
                    for (int i = deleteIndex; i < currentSize; i++)
                    {
                        studentList[i] = studentList[i + 1];
                    }
                    currentSize--;
                    displayStudent(studentList, currentSize);
                }
            break;
		}
			case 5: 
			break;
			
			case 6:
			break;
			
			case 7:
			    printf("Nhap status sinh vien can tim kiem:");
			    scanf("%d",&lookStatus);			 
			    for(int i=0;i<currentIndex;i++){
			  	if(studentList[i].status==lookStatus){
			  		check++;
			  		printf("Thong tin sinh vien co status la %d:\n",lookStatus);
			  		print(studentList[i]);
			  		printf("\n");
				  }
			    }
			    if(check==0){
			    	printf("Khong tim thay");
				}
				break;
			break;
			
			default:
            if (choice == 7)
            {
                printf("vui long chon tu 1-7\n");
            }
            else
            {
                printf("Sai cu phap , moi nhap lai\n");
            }
            break;
        }
    }

    return 0;
}

