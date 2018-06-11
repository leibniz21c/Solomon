/* In Develope of Solomon, -1 is standard error. */
#define S_ERR -1
#define INIT_ERR -2


/* To Boolean Variable  */
#define BOOL
#define TRUE 1
#define FALSE 0

#ifdef BOOL
typedef int boolean;
#endif


/* Channel Macro. --> in screen.c, to getMenu Funtion */
#define CH_EXIT 0  // get out from this program
#define CH_USET 1  // Set user info(information)
#define CH_HIST 2  // Show History
