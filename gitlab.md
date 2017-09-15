# GitLab 기능 살펴보기(9.3.4)

## User Settings
- Profile : 개인 프로필 관리
- Account : 계정 관리
  - Gitlab과 연계할 수 있는 Private Token 관리
  - Two-Factor 인증
  - Username 변경
- Applications : Gitlab의 OAuth를 사용할 Application을 셋팅
- Chat
- Access Tokens : Gitlab API에 대한 액세스를 위한 SSH Key 관리(Two-Factor Auth 필수)
- Emails
- Password
- Notifications
- SSH Keys : SSH Key 관리
- Preferences : Gitlab UI에 대한 설정
- Authentication log : 인증 로그

## Quick Menu
- Star
- Fork
- Copy URL
- Download
- Create new
- Notification setting

## Side Menu
- Project
  - Home
  - Activity : 프로젝트에 관련된 모든 활동로그
  - Cycle Analytics : 프로젝트에서 아이디어를 생산으로 옮기는 데 걸리는 시간을 대략적으로 보여줍니다.
- Repository
  - Files
  - Commits
  - Branches
  - Tags
  - Contributors
  - Graph
  - Compare
  - Charts
- Issues : 트렐로와 비슷
  - List
  - Board
  - Labels
  - Milestones
- Merge Requests
- Pipelines
  - Pipelines : 
  - Jobs
  - Schedules
  - Environments
  - Charts
- Wiki
- Snippets
- Settings
  - General
  - Members
  - Integrations
  - Repository
  - Pipelines

===

테스트 환경

http://de-pf01.fttinc.kr:18080/
root / ftt123!@#


java -jar build/libs/test-1.0.0.jar -Dspring.config.location="file:config/localhost/application.yml"


java -jar build/libs/test-1.0.0.war -Dspring.config.location="file:config/localhost/application.yml"



java -Dspring.config.location=file:config/localhost/application.properties -jar build/libs/sample_app-1.0.0.war


===

### gitlab runner 설치
sudo docker run -d --name gitlab-runner --restart always \
-p 19080:80 \
-v /srv/gitlab-runner/config:/etc/gitlab-runner \
-v /var/run/docker.sock:/var/run/docker.sock \
gitlab/gitlab-runner:latest



### container 접속 및 runner register
sudo docker exec -it gitlab-runner /bin/bash
container ~/> sudo gitlab-runner register



### 이미지 셋팅
centos:6
oraclejdk-8









