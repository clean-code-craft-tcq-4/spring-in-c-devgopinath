#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;

    if (( numberset == NULL_POINTER) && (setlength == 0))
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    else if (( numberset != NULL_POINTER) && (setlength > 0))
    {
        s.min = numberset[0];
        s.max = numberset[0];
        s.average = numberset[0];

        if (setlength > 1)
        {
            int index;

            for (index = 1; index < setlength; index++)
            {
                /* store the sum of values */
                s.average += numberset[index];

                /* check and replace value if s.min is more than value */
                if (numberset[index] < s.min)
                {
                    s.min = numberset[index];
                }
                /* check and replace value if s.max is less than value */
                if (numberset[index] > s.max)
                {
                    s.max = numberset[index];
                }
            }
            /* at last calculate the average value */
            s.average /= ((float)setlength);
        }
    }
    else
    {

    }

    return s;
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount = 1;
}

void ledAlerter(void)
{
    ledAlertCallCount = 1;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if ((isnan(computedStats.max) == false) && 
        (computedStats.max > maxThreshold))
    {
        (alerters[0])();
        (alerters[1])();
    }
}