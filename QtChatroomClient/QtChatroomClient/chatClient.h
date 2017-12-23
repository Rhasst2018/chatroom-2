#ifndef __CHAT_CLIENT_H__
#define __CHAT_CLIENT_H__


//ע��
#define ACTION_REGISTER        1
//��¼������
#define ACTION_LOGIN           2
//��ʼ����
#define ACTION_START_CHAT      3
//�˳�������
#define ACTION_QUIT        	   4

int Get(int socketfd, char* recvBuf);
int Post(int socketfd, int action, const char *userName, const char * password, const char* message);
void GetTime(char * timeBuf);





#endif //__CHAT_CLIENT_H__

