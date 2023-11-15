#include <bits/stdc++.h>
#include "variables.cpp"

using namespace std;

int getDelayGap()
{
  int largest_delay_gap = INT_MIN;

  for (int i = 0; i < no_of_aps; i++)
  {
    for (int j = 0; j < no_of_mds; j++)
    {
      if (d_uv[i][j] == -1)
        continue;

      int delay_gap = d_uv[i][j] - Tv[j];

      if (delay_gap > largest_delay_gap)
        largest_delay_gap = delay_gap;
    }
  }

  return largest_delay_gap;
}

double MDNA(AP broken_ap)
{

  int no_of_mds = broken_ap.connected_MDs.size();
  double max_delay_difference = INT_MIN;

  for (int i = 0; i < no_of_mds; i++)
  {
    int max_traffic = INT_MIN;
    MD *req_md = new MD();

    for (MD v : broken_ap.connected_MDs)
    {
      if (v.marked == false && max_traffic < v.traffic_requirement)
      {
        max_traffic = v.traffic_requirement;
        req_md = &v;
      }
    }

    AP *req_ap = new AP();
    double max_delay = INT_MIN;

    for (AP u : req_md->candidate_aps)
    {
      if (u.isBroken)
        continue;

      double delay = d_uv[u.id][(*req_md).id] - Tv[(*req_md).id];

      if (delay > max_delay)
      {
        max_delay_difference = max(delay, max_delay_difference);
        max_delay = delay;
        *req_ap = u;

        // if the power range is shorter than the required range to
        // cover MD v then extend the power range

        // if((*req_ap).power_range < )
      }
    }
  }

  return max_delay_difference;
}