#include <bits/stdc++.h>

using namespace std;

int no_of_APs = 100;
int no_of_MDs = 1000;

vector<vector<int>> decision_variable(100, vector<int>(1000));
int tolerable_delay = 100;
vector<vector<int>> transimission_delay(100, vector<int>(1000));
// vector of tolerable delay for all MDs

// AP class
class AP
{
public:
  int id;
  double power_range;
  vector<MD> connected_MDs;
  int switched_on;
  bool isBroken;

  //   bool markedAp;
  AP()
  {
    id = -1;
  }

  AP(int id, double power_range)
  {
    this->id = id;
    this->power_range = power_range;
  }

  void addConnectedMD(MD md)
  {
    connected_MDs.push_back(md);
  }

  void removeConnectedMD(MD md)
  {
    connected_MDs.erase(remove(connected_MDs.begin(), connected_MDs.end(), md), connected_MDs.end());
  }

  //   double getLoadDifference(AP other_ap) {
  //     return abs(load - other_ap.load);
  //   }
};

// MD class
class MD
{
public:
  int id;
  AP current_ap;
  bool marked;
  double traffic_requirement;
  vector<AP> candidate_aps;

  MD()
  {
    id = -1;
  }

  MD(int id, AP current_ap)
  {
    this->id = id;
    this->current_ap = current_ap;
    this->marked = false;
  }

  void addCandidateAP(AP ap)
  {
    candidate_aps.push_back(ap);
  }

  void removeCandidateAP(AP ap)
  {
    candidate_aps.erase(remove(candidate_aps.begin(), candidate_aps.end(), ap), candidate_aps.end());
  }
};

int getDelayGap()
{
  int largest_delay_gap = INT_MIN;

  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 1000; j++)
    {
      if (transimission_delay[i][j] == -1)
        continue;

      int delay_gap = transimission_delay[i][j] - tolerable_delay;

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

      double delay = transimission_delay[u.id][(*req_md).id] - tolerable_delay;

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