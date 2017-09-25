# Maven을 이용한 빌드관리

### Maven 소개
- https://maven.apache.org/
- 빌드 툴
- POM(Project Object Model) 기반
- Ant > Maven > Gradle 으로 진행중이고 Gradle로 완전 전환되는 것이 이상하지 않음.
- 철학 : 표준화된 프로젝트 레이아웃(CoC - Convention Over Configuration)
  컨피그와 컨벤션은 상반된 계념인데... 컨벤션을 더 중요시 하겠다.
  컨벤션은 Best Praectice를 통해 나오며 이를 통해 Spring이 탄생.
- 장점
  - 프로젝트 레이아웃
  - 자동 의존성 관리
  - 메인 저장소 사용가능
  - 플러그인을 통한 재사용
- 모든 장점이 gradle에도 동일하게 적용

### 설치
- Java 필수
- M2_HOME 환경변수 셋팅
- https://maven.apache.org/download.cgi

### 새프로젝트 만들기
- groupId, artifactId, version, package 지정
- archetype을 이용해 템플릿을 제공. 하지만 사실상 사용 잘 안함
- 순서
  ```bash
  mvn archetype:generate
  ```
  - default archetype인 quickstart를 선택
  - 버전 넘버 선택
  - groupId - kr.or.kosta
  - artifactId - hello
  - version 선택
  - package 선택
- 실행가능한 jar를 만들기 위해서 플러그인 설치(없으면 별도로 MANIFEST 파일을 만들어서 jar를 만들어 주어야 함)
  ```xml
  <build>
    <plugins>
      <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-jar-plugin</artifactId>
        <configuration>
          <archive>
            <manifest>
              <mainClass>kr.co.ftt.mvn_sample1.App</mainClass>
              <addClasspath>true</addClasspath>               
              <classpathPrefix>lib/</classpathPrefix>
            </manifest>
          </archive>
        </configuration>
      </plugin>
      <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-dependency-plugin</artifactId>
        <executions>
          <execution>
            <id>copy</id>
            <phase>install</phase>
            <goals>
              <goal>copy-dependencies</goal>
            </goals>
            <configuration>
              <outputDirectory>
                ${project.build.directory}/lib
              </outputDirectory>
            </configuration>
          </execution>
        </executions>
      </plugin>
    </plugins>
  </build>
  ```
- 프로젝트 사용
  ```bash
  cd hello
  mvn install
  java -jar target/hello-1.0-SNAPSHOT.jar
  ```

### 프로젝트 구조
- pom.xml이 무조건 있음. 이곳이 프로젝트 root
- ~/src/main/java 가 classpath의 root
- ~/src 는 모든 소스
- ~/target 은 모든 빌드 결과
- Super POM이 존재하고 이를 기본 적으로 상속받고 필요한 부분은 pom.xml에 override해서 정의
  ```bash
  mvn help:effective-pom
  ```

### 이클립스
- 프로젝트 import

### 메이븐 라이프사이클
- Built-in 라이프 사이클인 clean, build, site가 존재
- 각 단계를 phase라고 부름
- phase는 plugin 기반으로 동작함
- phase는 하나 이상의 goal로 구성됨
- 사실상 메이븐은 플랫폼이고 플러그인들로 기능을 확장하여 사용
```bash
mvn [Option] [Plugin]:[Goal(생략가능)] [Phase]
```
- Phase > Plugin > Goal

### 의존 라이브러리
- 프로젝트 모듈화를 통해 닷넷의 솔루션 처럼 여러 프로젝트를 묶어서 관리할 수 있음
- 순차적인 빌드만 지원하기 때문에 의존 순서가 애매해질 수 있음
- parents 프로젝트는 pom 으로 빌드처리 되어야 함

### 웹프로젝트
- 다이나믹 웹프로젝트를 기본으로 만들고 maven 프로젝트로 변경하는 것이 간단
- src/main/java, src/test/java 셋팅 후 컨텐츠 path를 src/main/web으로 지정

### 의존성 관리
- 스코프를 지정하면 모듈 파일들의 사용 수준들을 지정
- system 스코프는 로컬 라이브러리를 직접 지정이 필요
- exclusions로 필요 없는 특정 의존을 제외시킬 수 있음
- pom.xml에서 properties로 값 지정해 놓고 쓸 수 있음
- 정해져 있는 system properies가 있음

### 웹프로젝트 자동 배포
- 톰캣 설치 및 실행
- conf/tomcat-user.xml 수정 role 적용
- tomcat plugin 셋팅 in pom.xml

### 배포
- tomcat7-maven-plugin 을 통해 배포 처리
- install phase에 redeploy를 등록

### 넥서스
- ~/.m2/settings.xml

### 젠킨스
- 자바, 메이븐, 깃 기본 셋팅
- 빌드 자동 삭제 셋팅
