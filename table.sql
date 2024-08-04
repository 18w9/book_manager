### ͼ��ݶ��߱�

CREATE TABLE `reader` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL DEFAULT '' COMMENT '�û�����',
  `gender` TINYINT NOT NULL DEFAULT 1 COMMENT '�û��Ա�1-�У�2-Ů',
  `phone_number` VARCHAR(20) NOT NULL DEFAULT '' COMMENT '�绰����',
  PRIMARY KEY (`id`),
  UNIQUE INDEX `idx_phone_number` (`phone_number`) COMMENT '�绰����Ψһ����'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='ͼ��ݶ��߱�';

###ͼ����鼮��
CREATE TABLE book (
no INT UNSIGNED NOT NULL AUTO_INCREMENT,
name VARCHAR(255) NOT NULL COMMENT'�鼮��',
author VARCHAR(255) NOT NULL COMMENT'����',
category VARCHAR(100) COMMENT'����',
publisher VARCHAR(255) COMMENT'������',
publish_date DATE COMMENT '����ʱ��',
price DECIMAL(10, 2) COMMENT '�۸�',
number INT COMMENT'����',
PRIMARY KEY (no),
UNIQUE KEY unique_no (no)  COMMENT '�鼮���Ψһ����'
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

###���߽����
CREATE TABLE BorrowingRecords (
borrowingid INT UNSIGNED NOT NULL AUTO_INCREMENT,
readerid INT NOT NULL COMMENT'����id',
bookid INT NOT NULL COMMENT'�鼮id',
quantity INT NOT NULL COMMENT'���߽�����', 
bookStorage INT NOT NULL COMMENT'�鼮�洢��',
PRIMARY KEY(borrowingid),
UNIQUE KEY unique_borrowingid (borrowingid)  
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
