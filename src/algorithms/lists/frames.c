#include <anger_list_out.h>

int alloc_frame(List *pFrames)
{
    if(NULL == list_head(pFrames))
        return -1;

    int frame_number, *pFrame;
    if(list_del_next(pFrames, NULL, &pFrame)!=0)
    {
        return -1;
    }

    frame_number = *((int *)pFrame);
    free(pFrame);

    return frame_number;
}

int free_frame(List *pFrames, int frame_number)
{
    int *pData = (int *)malloc(sizeof(int));
    *pData = frame_number;

    if(0 != list_ins_next(pFrames, NULL, pData))
        return -1;

    return 0;
}
