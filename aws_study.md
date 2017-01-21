# AWS 막해보기

## Study 시나리오
### AWS 맛보기
1. 기본 EC2 설치
2. ssh 연결
3. 기본 설치(docker, git)
4. 샘플 프로젝트 띄우기

### docker
1. 구성요소 내용 확인
2. 설치
3. 기본 서버 로컬에 올려보기
4. 이미지 생성하기
5. AWS push

## 정리
### CLI - 우선 이걸 익히는게 먼저인게 아닌가...
- [AWS Document](https://aws.amazon.com/ko/cli/)
- ssh 연결은 key pair로 하지만 aws cli 사용은 api 사용이기 때문에 별도의 credential이 존재
- 키 등록이 기본
```shell
$ aws configure
AWS Access Key ID [****************YOJQ]: 
AWS Secret Access Key [****************5Mhd]:   
Default region name [ap-northeast-1]:
Default output format [json]:
```
- AMI access key와 secret key가 필요한데 secret key는 생성시에만 확인 가능하며 분실시에는 새로 만들어야 함
- CLI Shell : aws cli 명령을 손쉽게 입력할 수 있도록 자동완성을 지원하는 툴 [Link](https://github.com/awslabs/aws-shell)
- Amazon Linux AMI에 이미 깔려 있음. 때문에 gate용 amazon instance 띄워놓고 여기로만 ssh로 연결해도 될 듯

### Docker
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
  --env MYSQL_ROOT_PASSWORD="ever2489" \
  --env MYSQL_USER="hoolajjang" \
  --env MYSQL_PASSWORD="ever2489" \
  --env MYSQL_DATABASE="wordpress" \
  --name mysql-wp \
  --publish 3306:3306 \
  mysql;

docker run --restart=always --name wordpressdb -e MYSQL_ROOT_PASSWORD=ever2489 -e MYSQL_DATABASE=wordpress -d mysql:latest
docker run --restart=always -e WORDPRESS_DB_PASSWORD=ever2489 -d --name wordpress --link wordpressdb:mysql -p 8080:80 wordpress
```
- 전반적으로 잘 설명되어있는 곳 http://pyrasis.com/Docker/Docker-HOWTO

### 개발

### ECR
 - docker 이미지 레파지토리라고 보면 됨

### ECS
 - EC2 기반으로 한 docker container service

### CodeCommit
- 기능 자체가 너무 별로 없음
