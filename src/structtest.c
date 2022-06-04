//
// Created by code4j on 2022-05-16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    char b;
    int c;
} Body;
typedef struct {
    int like_count;
    int view_count;
    int photo_count;
} CountInfo;
typedef struct  {
    long id;
    int status;
    char* name;
    CountInfo* count;
} PolarisUser;

void test_size(PolarisUser* user) {
    printf("body size:%ld, object size:%ld\n", sizeof(PolarisUser), sizeof(user));
    Body* body = malloc(sizeof(Body));
    printf("shot size:%ld\n", sizeof(short));
    printf("body size:%ld, object size:%ld\n", sizeof(Body), sizeof(body));

}

PolarisUser* new_user_struct() {
    PolarisUser* user = malloc(sizeof(PolarisUser));
    user->id = 1L;
    user->name = "code4j";
    user->status = 2;
    user->count = malloc(sizeof(PolarisUser));
    user->count->like_count = 0;
    user->count->view_count = 0;
    user->count->photo_count = 0;
    return user;
}

int main() {
    PolarisUser* user = new_user_struct();
    printf("new account info:id:%ld,name:%s,status:%d,like_count:%d\n",
            user->id, user->name, user->status, user->count->like_count);
//    free(user);
    test_size(user);
    return 0;
}