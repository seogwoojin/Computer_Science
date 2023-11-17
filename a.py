from bs4 import BeautifulSoup
import pandas as pd

import requests

url = 'http://www.statiz.co.kr/stat.php?mid=stat&re=0&ys=1982&ye=2023&se=0&te=&tm=&ty=0&qu=auto&po=0&as=&ae=&hi=&un=&pl=&da=1&o1=WAR_ALL_ADJ&o2=TPA&de=1&tr=&cv=&ml=1&sn=30&pa=0&si=&cn=&lr=1'

response = requests.get(url)

html = response.text
soup = BeautifulSoup(html, 'html.parser')
temp = soup.find_all("table")[0]
print(temp)
df = pd.DataFrame(index = range(343), columns = ["순", "이름", "연도", "WAR", "-", "타석", "타수", "득점", "안타", "2루타", "3루타", "홈런", "루타", "타점",
                                                 "도루", "도루실패", "볼넷", "사구", "고의사구", "삼진"])
l = 0
temp2 = temp.find_all("tr")[3]
for j in range(3,414):
    temp2 = temp.find_all("tr")[j]
    if len(temp2.find_all("td")) == 31:
        for i in range(31):
            temp3 = temp2.find_all("td")[i]

            temp4 = temp3.get_text()
            if(i==2 or (5<=i and i<=19)):
              df.iloc[l,i]=int(temp4)
            elif(i==3 ):
              df.iloc[l,i]=float(temp4)
            else:
              df.iloc[l,i]=temp4

        l += 1

print(df)