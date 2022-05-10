#ifndef STATS_H
#define STATS_H

#define NULL_POINTER    ((void *)0)

struct Stats
{
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numberset, int setlength);

void emailAlerter(void);
void ledAlerter(void);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

#endif /* STATS_H */
