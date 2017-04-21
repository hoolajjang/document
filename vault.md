# vault

## Architecture
- Storage Backend : 암호화 된 데이터의 영구 저장을 담당합니다.
- Barrier : Vault를 둘러싼 암호화된 강철이고 콘크리트
- Secret Backend
- Audit Backend : 감사 로그 관리를 담당합니다.
- Credential Backend : Vault에 연결중인 사용자 또는 응용 프로그램을 인증하는 데 사용됩니다.
- Client Token : 클라이언트 토큰은 개념적으로 웹 사이트의 세션 쿠키와 유사합니다. 사용자가 인증되면 Vault는 향후 요청에 사용되는 클라이언트 토큰을 반환합니다.
- Secret
- Server

## High Availability
- Vault는 고 가용성 배포를 지원하여 시스템 또는 프로세스 장애를 최소화 할 수 있도록 설계되었습니다.
- Vault는 일반적으로 컴퓨팅 요구 사항이 아닌 스토리지 백엔드의 IO 한계로 제한됩니다.
- 저장소 백엔드를 공유하는 여러 Vault 서버의 경우 다른 인스턴스가 모두 대기 상태 인 동안 언제든지 단일 인스턴스 만 활성화됩니다.
- active-standby 구성
- 모든 처리는 active가 하고 standby는 redirect 처리만 함

## Security Model

## Telemetry(원격측정)

## Token Authentication

## Key Rotation

## Replication (Vault Enterprise)


## Keyword
- Policy : ACL에 대한 정책



                     Cgo: disabled
         Cluster Address: https://127.0.0.1:8201
              Listener 1: tcp (addr: "127.0.0.1:8200", cluster address: "127.0.0.1:8201", tls: "disabled")
               Log Level: info
                   Mlock: supported: false, enabled: false
        Redirect Address: http://127.0.0.1:8200
                 Storage: inmem
                 Version: Vault v0.7.0
             Version Sha: 7b50b2cb13c707857e5d1f491e3954282c95749f

Unseal Key: ia+OzRLpvyVdc9NiZBRu13oaQO9RYBFC+epnAmIkL6E=
Root Token: 86f2f3b2-dc4b-48ec-1490-c91869145d8c
