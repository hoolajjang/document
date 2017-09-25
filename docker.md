Docker Study
===

## 요약
- [공식문서](https://docs.docker.com)
- [예제](http://blog.saltfactory.net/docker/running-docker-on-mac-using-with-docker-machine.html)
- 설치는 매우 간단 하지만 구성요소의 구분이 처음에 좀 생소함
  - 구성요소
    - Docker Client
    - Docker machine(or vergrant(LCX), docker-osx, boot2docker(Tiny Core OS))
      - docker를 돌릴 수 있는 가상 머신이라 생각하면 편해짐.
      - 정확하게는 가상 호스트에서 docker engine을 설치하고 docker-machine 명령을 통해 관리할 수 있는 툴.
      - local이든 cloud건 docker host를 생성할 수 있음
      - boot2docker가 많이 사용되었었는데 최근 이걸 밀고 있음
      - 그래도 VirtualBox는 필요함
    - Docker Compose
    - Docker Kitemactic
    - Virtual Box
- AWS이 예제가 매우 좋은... http://docs.aws.amazon.com/ko_kr/AmazonECR/latest/userguide/get-set-up-for-amazon-ecr.html
- http://docs.aws.amazon.com/AmazonECR/latest/userguide/docker-basics.html#install_docker
- 흐름
  - machine(장비) 셋팅
- 주 명령어
  - docker images : 가지고 있는 이미지 확인
  - docker pull : 레파지토리에서 이미지 확보
  - docker build : 소스를 이미지화 할때 사용
  - docker run : 이미지를 프로세스에 올림
  - docker exec : 컨테이너에 명령을 입력할때 사용(이걸로 쉘 접속하는 거임)
  - docker commit : 현재 컨테이너의 상태를 image로 만듬
  - docker diff : 현재 컨테이너의 변경점을 확인

```shell
docker run \
  --detach \
  --env MYSQL_ROOT_PASSWORD="****89" \
  --env MYSQL_USER="****ng" \
  --env MYSQL_PASSWORD="****89" \
  --env MYSQL_DATABASE="wordpress" \
  --name mysql-wp \
  --publish 3306:3306 \
  mysql;

docker run --restart=always --name wordpressdb -e MYSQL_ROOT_PASSWORD=ever2489 -e MYSQL_DATABASE=wordpress -d mysql:latest
docker run --restart=always -e WORDPRESS_DB_PASSWORD=ever2489 -d --name wordpress --link wordpressdb:mysql -p 8080:80 wordpress
```
- 전반적으로 잘 설명되어있는 곳 http://pyrasis.com/Docker/Docker-HOWTO (이 사람이 docker 책 저자임)
- docker login 인증 정보는 docker가 호스트에서 root로 실행되어애 하기 때문에 /root/.docker/config.json에 저장됨

- 전반적으로 잘 설명되어있는 곳 http://pyrasis.com/Docker/Docker-HOWTO (이 사람이 docker 책 저자임)
- docker login 인증 정보는 docker가 호스트에서 root로 실행되어애 하기 때문에 /root/.docker/config.json에 저장됨



- centos6 + oraclejre8 환경으로 이미지 생성
```
git clone git@github.com:hoolajjang/docker.git
cd docker/java/centos6-oraclejre8
docker build -t centos6-oraclejre8:0.1 ./
```

- docker hub에서 바로 가져오기
```
docker pull hoolajjang/centos6-oraclejre8:0.1
docker run -d --name java8 -i -t cnetos6-oraclejre8:0.1 /bin/bash 
```






