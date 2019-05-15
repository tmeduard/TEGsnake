import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { HomebarComponent } from './homebar.component';

describe('HomebarComponent', () => {
  let component: HomebarComponent;
  let fixture: ComponentFixture<HomebarComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ HomebarComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HomebarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
