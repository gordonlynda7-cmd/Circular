# Cloud Regions Used in This Demo

RoundRobin seeds and offers these real AWS and Google Cloud regions as
server options. No live connection is made to AWS or Google Cloud -
these are used only as realistic, recognizable names and locations for
the simulation.

| Provider     | Region Code       | Location                  |
|--------------|--------------------|----------------------------|
| AWS          | us-east-1          | N. Virginia, USA           |
| AWS          | us-west-2          | Oregon, USA                |
| AWS          | eu-west-1          | Ireland                    |
| AWS          | ap-southeast-1     | Singapore                  |
| Google Cloud | us-central1        | Council Bluffs, Iowa       |
| Google Cloud | europe-west1       | St. Ghislain, Belgium      |
| Google Cloud | asia-northeast1    | Tokyo, Japan               |

## Starting servers

When the program launches, it automatically adds three servers to the
ring so there's something to route requests to right away:

1. AWS us-east-1 (N. Virginia, USA)
2. Google Cloud us-central1 (Council Bluffs, Iowa)
3. Google Cloud europe-west1 (St. Ghislain, Belgium)

The remaining four regions can be added at any time through the
program's "Add Server" menu option.

## Source

Region codes and locations are drawn from publicly available AWS and
Google Cloud documentation:
- AWS Regions: https://aws.amazon.com/about-aws/global-infrastructure/regions_az/
- Google Cloud Regions: https://cloud.google.com/about/locations
