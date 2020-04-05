#include <iostream>
using namespace std;
struct element
{
    int school;
    int roll;
    struct element *ptr;
};

void print(struct element *ptr){
    if(ptr ==NULL){
        cout<<"ptr is NULL"<<endl;
    }
    while(ptr!=NULL){
        cout<<ptr->school<<" "<<ptr->roll<<endl;
        ptr=ptr->ptr;
    }
}

int main()
{
    int n;
    cin >> n;
    struct element *sptr = NULL;
    struct element *eptr = NULL;
    struct element *ptr1 = NULL;
    struct element *ptr2 = NULL;
    struct element *ptr3 = NULL;
    struct element *ptr4 = NULL;

    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    for (int i = 0; i < n; i++)
    {
        char test;
        cin >> test;

        switch (test)
        {
        case 'E':
        {
            int school, roll;
            cin >> school >> roll;

            struct element *temp = new struct element;
            temp->school = school;
            temp->roll = roll;
            temp->ptr = NULL;

            if (sptr == NULL)
            {
                sptr = temp;
                eptr = temp;

                switch (school)
                {
                case 1:
                    //for school 1
                    ptr1 = sptr;
                    counter1++;
                    break;
                case 2:
                    //for school 2
                    ptr2 = sptr;
                    counter2++;
                    break;
                case 3:
                    //for school 3
                    ptr3 = sptr;
                    counter3++;
                    break;
                default:
                    //for school 4
                    ptr4 = sptr;
                    counter4++;
                }
            }
            else
            {
                switch (school)
                {
                case 1:
                    //for school 1
                    if (counter1 == 0)
                    {
                        eptr->ptr = temp;
                        ptr1 = temp;
                        eptr = eptr->ptr;
                    }
                    else
                    {
                        struct element *tmptr = ptr1->ptr;
                        if(eptr == ptr1){
                            eptr = temp;
                        }
                        ptr1->ptr = temp;
                        temp->ptr = tmptr;
                        
                    }
                    counter1++;
                    break;
                case 2:
                    //for school 2
                    if (counter2 == 0)
                    {
                        eptr->ptr = temp;
                        ptr2 = temp;
                        eptr = eptr->ptr;
                    }else{
                        struct element *tmptr = ptr2->ptr;
                        if(eptr == ptr2){
                            eptr = temp;
                        }
                        ptr2->ptr = temp;
                        temp->ptr = tmptr;
                    }
                    counter2++;
                    break;
                case 3:
                    //for school 3
                    if (counter3 == 0)
                    {
                        eptr->ptr = temp;
                        ptr3 = temp;
                        eptr = eptr->ptr;
                    }else{
                        struct element *tmptr = ptr3->ptr;
                        if(eptr == ptr3){
                            eptr = temp;
                        }
                        ptr3->ptr = temp;
                        temp->ptr = tmptr;
                    }
                    counter3++;
                    break;
                default:
                    //for school 4
                    if (counter1 == 0)
                    {
                        eptr->ptr = temp;
                        ptr4 = temp;
                        eptr = eptr->ptr;
                    }else{
                        struct element *tmptr = ptr4->ptr;
                        if(eptr == ptr4){
                            eptr = temp;
                        }
                        ptr4->ptr = temp;
                        temp->ptr = tmptr;
                    }
                    counter4++;
                }
            }
            break;
        }
        default:
            //do some stuff
            cout<<sptr->school<<" "<<sptr->roll<<endl;
            switch (sptr->school)
                {
                case 1:
                    //for school 1
                    counter1--;
                    break;
                case 2:
                    //for school 2
                    counter2--;
                    break;
                case 3:
                    //for school 3
                    counter3--;
                    break;
                default:
                    //for school 4
                    counter4--;
                }
            sptr = sptr->ptr;
            if(counter1+counter2+counter3+counter4 == 0){
                sptr = NULL;
                eptr= NULL;
            }
        }
        
        print(sptr);
    }
    return 0;
}