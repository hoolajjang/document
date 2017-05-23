# vault

## Architecture
- Storage Backend : 암호화 된 데이터의 영구 저장을 담당합니다.
- Barrier : Vault를 둘러싼 암호화된 강철이고 콘크리트
- Secret Backend : 실제 키들이 암호화 되어 저장되는 공간
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
- 기밀성, 무결성, 가용성, 책임성, 인증을 제공

## Telemetry(원격측정)

## Token Authentication
- 킄라이언트 인증용

## Key Rotation
- 주기적인 변경

## Replication (Vault Enterprise)
- Primary/Secondary(1:N) replication 지원
- 다중 데이터센터 
- 요청 처리를 늘릴 수 있음

## Keyword
- Policy : ACL에 대한 정책

## Seal / Unseal
- 봉인모드를 의미하면 마스터키가 없으면 상태 변경이 불가능함



### Memo
```

                     Cgo: disabled
         Cluster Address: https://127.0.0.1:8201
              Listener 1: tcp (addr: "127.0.0.1:8200", cluster address: "127.0.0.1:8201", tls: "disabled")
               Log Level: info
                   Mlock: supported: false, enabled: false
        Redirect Address: http://127.0.0.1:8200
                 Storage: inmem
                 Version: Vault v0.7.0
             Version Sha: 7b50b2cb13c707857e5d1f491e3954282c95749f

==> WARNING: Dev mode is enabled!

In this mode, Vault is completely in-memory and unsealed.
Vault is configured to only have a single unseal key. The root
token has already been authenticated with the CLI, so you can
immediately begin using the Vault CLI.

The only step you need to take is to set the following
environment variables:

    export VAULT_ADDR='http://127.0.0.1:8200'

The unseal key and root token are reproduced below in case you
want to seal/unseal the Vault or play with authentication.

Unseal Key: QEB27dT0vkfAI3IpUAB0c7YgQer/yJ4kSbgBGYaEHIA=
Root Token: e3cfa8b7-71c8-653d-f98c-0dab45fee682

---

// start server
vault server -dev &
export VAULT_ADDR='http://127.0.0.1:8200'

// create policy
vi acl.hcl
vault policy-write secret acl.hcl
vault token-create -policy="secret"
Key            	Value
---            	-----
token          	f72b4cb2-49d6-9b36-a1e5-0f35d4d817cd
token_accessor 	610c5ee7-62bc-3fcf-7d3e-00a43615b16c
token_duration 	768h0m0s
token_renewable	true
token_policies 	[default secret]

vault auth f72b4cb2-49d6-9b36-a1e5-0f35d4d817cd


// key,value test
vault write secret/tony value=kimkwanghee
vault read secret/tony

vault write secret/foo value=yes




// mount list
vault mounts
vault mount mysql -path=/mysql
vault write mysql/config/connection connection_url="root@tcp(127.0.0.1:3306)/"
vault write mysql/config/lease lease=1h lease_max=24h

// connect local mysql
mysql -uroot -p





mysql -h de-c-my-db.fttinc.kr -P 19336 -udev433 -p 
433eoqkr)(!





```

