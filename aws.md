# AWS 막해보기

## Study 시나리오
### AWS 맛보기
1. 기본 EC2 설치
2. ssh 연결
3. 기본 설치(docker, git)
4. 샘플 프로젝트 띄우기

## 정리
### CLI - 우선 이걸 익히는게 먼저인게 아닌가...
- [AWS Document](https://aws.amazon.com/ko/cli/)
- ssh 연결은 key pair로 하지만 aws cli 사용은 api 사용이기 때문에 별도의 credential이 존재
- 해당 instance에 role을 부여하면 필요 없음
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

### 개발

### ECR
 - docker 이미지 레파지토리라고 보면 됨

### ECS
 - EC2 기반으로 한 docker container service

### CloudFormation
 - AWS Stack를 도식화해서 만들고 template를 만들 수 있음

### CodeCommit
- 기능 자체가 너무 별로 없음

### CodeDeploy
- json 파일로 배포 설정

### CodeBuild
- json 파일로 빌드 설정

